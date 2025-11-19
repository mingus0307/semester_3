package Managers;

import Core.GameWorld;
import Data.MapData;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class MapManager {

    private static BufferedImage ground;
    private static BufferedImage wall;
    private static BufferedImage floor;
    private static BufferedImage start;
    private static BufferedImage end;
    private static BufferedImage towerSpots;

    static {
        try {
            ground = ImageIO.read(new File("src/Resources/ground.jpg"));
            wall = ImageIO.read(new File("src/Resources/wall.jpg"));
            floor = ImageIO.read(new File("src/Resources/way.png"));
            start = ImageIO.read(new File("src/Resources/start.png"));
            end = ImageIO.read(new File("src/Resources/finish.png"));
            towerSpots = ImageIO.read(new File("src/Resources/towerSpot.png"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void render(Graphics2D g2, GameWorld gameWorld) {
        MapData map = gameWorld.getMap();

        Rectangle bounds = g2.getClipBounds();
        double width = bounds.getWidth();
        double height = bounds.getHeight();

        double tileWidth = width / map.tiles[0].length;
        double tileHeight = height / map.tiles.length;

        for (int row = 0; row < map.tiles.length; row++) {
            for (int col = 0; col < map.tiles[0].length; col++) {

                BufferedImage img = switch (map.tiles[row][col]) {
                    case 0 -> ground;
                    case 1 -> wall;
                    case 2 -> floor;
                    case 3 -> start;
                    case 4 -> end;
                    case 5 -> towerSpots;
                    default -> floor;
                };

                g2.drawImage(img,
                        (int)(col * tileWidth),
                        (int)(row * tileHeight),
                        (int) tileWidth,
                        (int) tileHeight,
                        null);
            }
        }
    }
}


