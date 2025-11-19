package UI;

import de.hsh.progproj.systembreach.SystemBreachGame;

import javax.swing.*;
import java.awt.*;

public class MainMenu extends JPanel {

    public MainMenu() {

        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

        JButton startButton = new JButton("start");
        JButton levelButton = new JButton("levels");
        JButton settingsButton = new JButton("settings");
        JButton exitButton = new JButton("cd ..");

        startButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        levelButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        settingsButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        exitButton.setAlignmentX(Component.CENTER_ALIGNMENT);

        // --- Buttons verknüpfen dein eigenes Spiel System Breach ---
        startButton.addActionListener(e -> SystemBreachGame.startGame("level1"));
        levelButton.addActionListener(e -> SystemBreachGame.showLevelScreen());
        settingsButton.addActionListener(e -> SystemBreachGame.showSettings());

        // zurück zum Launcher-Menü
        exitButton.addActionListener(e -> de.hsh.progproj.launcher.Main.showSelectionScreen());

        add(Box.createVerticalStrut(40));
        add(startButton);
        add(Box.createVerticalStrut(20));
        add(levelButton);
        add(Box.createVerticalStrut(20));
        add(settingsButton);
        add(Box.createVerticalStrut(20));
        add(exitButton);
    }
}

