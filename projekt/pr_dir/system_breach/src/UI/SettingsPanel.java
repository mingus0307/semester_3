package UI;

import de.hsh.progproj.systembreach.SystemBreachGame;

import javax.swing.*;
import java.awt.*;

public class SettingsPanel extends JPanel {

    public SettingsPanel() {

        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        setAlignmentX(Component.CENTER_ALIGNMENT);

        JLabel titleLabel = new JLabel("Einstellungen");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 26));
        titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

        JLabel volumeLabel = new JLabel("Musiklautstärke");
        volumeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

        JSlider volumeSlider = new JSlider(0, 100, 50);
        volumeSlider.setMajorTickSpacing(20);
        volumeSlider.setMinorTickSpacing(5);
        volumeSlider.setPaintTicks(true);
        volumeSlider.setPaintLabels(true);
        volumeSlider.setAlignmentX(Component.CENTER_ALIGNMENT);

        JButton backButton = new JButton("Zurück");
        backButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        backButton.addActionListener(e -> SystemBreachGame.showMainMenu());

        add(Box.createVerticalStrut(40));
        add(titleLabel);
        add(Box.createVerticalStrut(30));
        add(volumeLabel);
        add(Box.createVerticalStrut(10));
        add(volumeSlider);
        add(Box.createVerticalStrut(30));
        add(backButton);
        add(Box.createVerticalGlue());
    }
}
