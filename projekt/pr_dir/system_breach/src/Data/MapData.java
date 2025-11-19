package Data;



import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.io.IOException;


public class MapData {
    public int width;
    public int height;
    public int[][] tiles;

    // lädt automatisch die Map aus einem JSON file und gibt ein Object der Klasse MapData zurück
    public static MapData load(String path) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        return mapper.readValue(new File(path), MapData.class);
    }
}
