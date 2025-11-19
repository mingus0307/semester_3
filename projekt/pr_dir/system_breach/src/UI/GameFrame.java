package UI;

import javax.swing.*;
import java.awt.*;

public class GameFrame extends JFrame {

    private final CardLayout layout = new CardLayout();
    private final JPanel mainContainer = new JPanel(layout);

    public GameFrame() {
        setTitle("System Breach – Main Menu");
        setSize(800, 600);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        add(mainContainer);
    }

    public void addScreen(JPanel panel, String name) {
        mainContainer.add(panel, name);
    }

    public void showScreen(String name) {
        layout.show(mainContainer, name);
    }

    public void showGame(String level1) {
    }

    public void showLevels() {
    }

    public void showSettings() {
    }

    public void exitGame() {

    }
}

