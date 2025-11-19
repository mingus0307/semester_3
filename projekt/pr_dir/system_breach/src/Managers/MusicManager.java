package Managers;

import javax.sound.sampled.*;
import java.io.IOException;
import java.net.URL;

public class MusicManager {

    private static Clip clip;

    public enum Track {
        MAIN_MENU("/Resources/menu.wav"),
        GAMEPLAY("/Resources/gameplay.wav"),
        GAME_OVER("/Resources/gameover.wav");

        private final String path;
        Track(String path) { this.path = path; }
        public String getPath() { return path; }
    }

    public static void play(Track track, boolean loop) {
        stop();

        try {
            URL url = MusicManager.class.getResource(track.getPath());
            AudioInputStream audioIn = AudioSystem.getAudioInputStream(url);

            clip = AudioSystem.getClip();
            clip.open(audioIn);

            if (loop) {
                clip.loop(Clip.LOOP_CONTINUOUSLY);
            } else {
                clip.start();
            }

        } catch (UnsupportedAudioFileException | IOException | LineUnavailableException e) {
            throw new RuntimeException("Konnte Sound nicht laden: " + track.getPath(), e);
        }
    }

    public static void stop() {
        if (clip != null) {
            clip.stop();
            clip.close();
            clip = null;
        }
    }

    public static void setVolume(double volume0to1) {
        if (clip == null) return;

        FloatControl gain = (FloatControl) clip.getControl(FloatControl.Type.MASTER_GAIN);

        float min = gain.getMinimum(); // z.B. -80 dB
        float max = gain.getMaximum(); // z.B. +6 dB

        float volumeDb = (float)(min + (max - min) * volume0to1);
        gain.setValue(volumeDb);
    }
}

