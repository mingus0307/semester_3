package UI;

import de.hsh.progproj.systembreach.SystemBreachGame;

import javax.swing.*;
import java.awt.*;

public class LevelPanel extends JPanel {

    public LevelPanel() {
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

        JLabel titleLabel = new JLabel("Levels");
        titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        titleLabel.setFont(new Font("Arial", Font.BOLD, 26));

        JPanel levelBox = new JPanel();
        levelBox.setLayout(new BoxLayout(levelBox, BoxLayout.X_AXIS));
        levelBox.setAlignmentX(Component.CENTER_ALIGNMENT);

        levelBox.add(createLevelTile("Level 1", "level1", "src/Resources/preview.png"));
        levelBox.add(Box.createHorizontalStrut(40));
        levelBox.add(createLevelTile("Level 2", "level2", "src/Resources/preview.png"));
        levelBox.add(Box.createHorizontalStrut(40));
        levelBox.add(createLevelTile("Level 3", "level3", "src/Resources/preview.png"));

        JButton backButton = new JButton("Zurück");
        backButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        backButton.addActionListener(e -> SystemBreachGame.showMainMenu());

        add(Box.createVerticalStrut(40));
        add(titleLabel);
        add(Box.createVerticalStrut(40));
        add(levelBox);
        add(Box.createVerticalStrut(40));
        add(backButton);
    }

    private JPanel createLevelTile(String name, String levelKey, String imagePath) {
        JPanel tile = new JPanel();
        tile.setLayout(new BoxLayout(tile, BoxLayout.Y_AXIS));
        tile.setAlignmentX(Component.CENTER_ALIGNMENT);

        ImageIcon icon = new ImageIcon(imagePath);
        Image scaled = icon.getImage().getScaledInstance(160, 100, Image.SCALE_SMOOTH);
        JLabel preview = new JLabel(new ImageIcon(scaled));
        preview.setAlignmentX(Component.CENTER_ALIGNMENT);

        JButton button = new JButton(name);
        button.setAlignmentX(Component.CENTER_ALIGNMENT);

        button.addActionListener(e -> SystemBreachGame.startGame(levelKey));

        tile.add(preview);
        tile.add(Box.createVerticalStrut(10));
        tile.add(button);

        return tile;
    }
}



