import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Genre {
    private int genreID;
    private String genre;

    public int getGenreID() {
        return genreID;
    }

    public void setGenreID(int genreID) {
        this.genreID = genreID;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }
    public void insert() throws Exception {

        int id;

        // ID aus Sequenz holen
        String sql = "SELECT nextval('genre_id_seq') AS id";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {
            if (!rs.next()) throw new Exception("Keine neue ID aus Sequenz erhalten");
            id = rs.getInt("id");
        }

        sql = "insert into Genre (genre_id, genre) values (?, ?)";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql)) {
            stmt.setInt(1, id);
            stmt.setString(2, genre);
            stmt.executeUpdate();
        }
        this.setGenreID(id);
    }

}
