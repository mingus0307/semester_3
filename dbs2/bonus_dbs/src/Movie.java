import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Movie {
    private int movieID;
    private String title;
    private String type;
    private int year;

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getMovieID() {
        return movieID;
    }

    public void setMovieID(int movieID) {
        this.movieID = movieID;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void insert() throws Exception {
        int id;

        // ID aus Sequenz holen
        String sql = "SELECT nextval('movie_id_seq') AS id";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {
            if (!rs.next()) throw new Exception("Keine neue ID aus Sequenz erhalten");
            id = rs.getInt("id");
        }

        sql = "INSERT INTO movie(movie_id, title, type, year) VALUES (?, ?, ?, ?)";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql)) {
            stmt.setInt(1, id);
            stmt.setString(2, title);
            stmt.setString(3, type);
            stmt.setInt(4, year);
            stmt.executeUpdate();
        }
        this.setMovieID(id);
    }

    public void update(Connection con)throws SQLException {
        String sql = "update Movie set title=?,type=?,year=? where id=?";
        PreparedStatement pst = con.prepareStatement(sql);
        pst.setString(1,  title);
        pst.setString(2,type);
        pst.setInt(3,year);
        pst.setInt(4,movieID);
        pst.executeUpdate();
    }

    public void delete()throws SQLException {
        String sql = "delete from Movie where id=?";
        Connection con = DBConnection.getConnection();

        PreparedStatement pst = con.prepareStatement(sql);
        pst.setInt(1, movieID);
        pst.executeUpdate();
    }
}
