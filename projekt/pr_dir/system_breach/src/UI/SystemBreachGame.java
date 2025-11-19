package de.hsh.progproj.systembreach;

import UI.MainMenu;
import UI.LevelScreen;
import UI.SettingsMenu;
import Core.GameView;


import de.hsh.progproj.launcher.Main;

import javax.swing.*;

public class SystemBreachGame {

    public static void start() {
        showMainMenu();
    }

    public static void showMainMenu() {
        replace(new MainMenu());
    }

    public static void showLevelScreen() {
        replace(new LevelPanel());
    }

    public static void showSettings() {
        replace(new SettingsPanel());
    }

    public static void startGame(String level) {
        replace(new GamePanel(level));
    }

    private static void replace(JPanel panel) {
        JFrame window = Main.getWindow();
        window.getContentPane().removeAll();
        window.add(panel);
        window.revalidate();
        window.repaint();
    }
}

