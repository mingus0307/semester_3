import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class MovieGenre {

    private int movie;
    private int genre;

    public int getGenre() {
        return genre;
    }

    public void setGenre(int genre) {
        this.genre = genre;
    }

    public int getMovie() {
        return movie;
    }

    public void setMovie(int movie) {
        this.movie = movie;
    }

    public void insert() throws SQLException {
        String sql = "INSERT INTO moviegenre (movie, genre) VALUES (?, ?)";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql)) {
            stmt.setInt(1, movie);
            stmt.setInt(2, genre);
            stmt.executeUpdate();
        }
    }

}
