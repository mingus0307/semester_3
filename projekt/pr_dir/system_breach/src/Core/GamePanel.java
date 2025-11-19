package Core;

import Data.MapData;
import Managers.MapManager;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;

public class GamePanel extends JPanel {

    private final MapData mapData;
    private final GameWorld gameWorld;
    private final MapManager renderer;

    private Timer gameLoop;
    private long lastFrameTime;

    public GamePanel(String level) {

        try {
            this.mapData = MapData.load("maps/" + level + ".json");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        this.gameWorld = new GameWorld(mapData);
        this.renderer = new MapManager();

        setBackground(Color.BLACK);

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {

                double tileWidth = getWidth() / (double) mapData.tiles[0].length;
                double tileHeight = getHeight() / mapData.tiles.length;

                int col = (int)(e.getX() / tileWidth);
                int row = (int)(e.getY() / tileHeight);

                gameWorld.placeTower(row, col);
            }
        });

        addComponentListener(new ComponentAdapter() {
            @Override
            public void componentResized(ComponentEvent e) {
                repaint();
            }
        });

        startLoop();
    }

    /** Der eigentliche GameLoop */
    private void startLoop() {
        lastFrameTime = System.nanoTime();

        gameLoop = new Timer(16, e -> {
            long now = System.nanoTime();
            double delta = (now - lastFrameTime) / 1_000_000_000.0;
            lastFrameTime = now;

            gameWorld.update(delta); // <--- MUSST DU IN GAMEWORLD NOCH BAUEN
            repaint();
        });

        gameLoop.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        renderer.render((Graphics2D) g, gameWorld);
        gameWorld.renderEntities((Graphics2D) g); // <--- optional
    }

    public void stopLoop() {
        if (gameLoop != null) gameLoop.stop();
    }
}

