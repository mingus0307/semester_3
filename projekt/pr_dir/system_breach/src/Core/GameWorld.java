package Core;

import Data.MapData;
import Entities.towers.Tower;
import Entities.enemies.Enemy;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class GameWorld {

    private final MapData map;

    // Entities für später
    private final List<Tower> towers = new ArrayList<>();
    private final List<Enemy> enemies = new ArrayList<>();

    public GameWorld(MapData map) {
        this.map = map;
    }

    public MapData getMap() {
        return map;
    }

    /**
     * Wird pro Frame vom GameLoop aufgerufen.
     * delta = Sekunden seit letztem Frame
     */
    public void update(double delta) {

        // Gegner bewegen
        for (Enemy e : enemies) {
            e.update(delta);
        }

        // Türme updaten (z.B. Schießen)
        for (Tower t : towers) {
            t.update(delta, enemies);
        }

        // Entferne tote Gegner
        enemies.removeIf(e -> e.isDead());
    }

    /**
     * Zeichne Gegner, Türme usw.
     */
    public void renderEntities(Graphics2D g2) {

        // Türme rendern
        for (Tower t : towers) {
            t.render(g2);
        }

        // Gegner rendern
        for (Enemy e : enemies) {
            e.render(g2);
        }
    }

    /**
     * Platziert einen Turm auf einem Grid-Feld (row, col).
     * Nur möglich, wenn map.tiles[row][col] == 5 (deine towerSpot Tiles)
     */
    public void placeTower(int row, int col) {

        // Grenzen prüfen (damit kein ArrayOutOfBounds)
        if (row < 0 || col < 0 || row >= map.tiles.length || col >= map.tiles[0].length) {
            return;
        }

        // Nur auf Tower-Spots (Tile = 5)
        if (map.tiles[row][col] != 5) {
            return;
        }

        // Prüfen ob dort schon ein Tower steht
        for (Tower t : towers) {
            if (t.getRow() == row && t.getCol() == col) {
                return; // Tower existiert schon
            }
        }

        // Neuen Turm setzen
        towers.add(new Tower(row, col));
    }

    // Für später (wenn du Gegner spawnen willst):
    public void addEnemy(Enemy e) {
        enemies.add(e);
    }
}
