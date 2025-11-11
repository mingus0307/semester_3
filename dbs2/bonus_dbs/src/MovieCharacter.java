import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class MovieCharacter {
    private int movCharID;
    private String character;
    private String alias;
    private int position;
    private int movie;
    private int actor;

    public int getMovie() {
        return movie;
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    public int getMovCharID() {
        return movCharID;
    }

    public void setMovCharID(int movCharID) {
        this.movCharID = movCharID;
    }

    public String getCharacter() {
        return character;
    }

    public void setCharacter(String character) {
        this.character = character;
    }

    public String getAlias() {
        return alias;
    }

    public void setAlias(String alias) {
        this.alias = alias;
    }

    public int getActor() {
        return actor;
    }

    public void setActor(int actor) {
        this.actor = actor;
    }

    public void setMovie(int movie) {
        this.movie = movie;
    }

    public void insert() throws Exception {
        int id;


        String sql = "SELECT nextval('movchar_id_seq') AS id";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {
            if (!rs.next())
                throw new Exception("Keine neue ID aus Sequenz erhalten");
            id = rs.getInt("id");
        }


        sql = "INSERT INTO moviecharacter (movchar_id, character, alias, position, movie, actor) " +
                "VALUES (?, ?, ?, ?, ?, ?)";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql)) {
            stmt.setInt(1, id);
            stmt.setString(2, character);
            stmt.setString(3, alias);
            stmt.setInt(4, position);
            stmt.setInt(5, movie);
            stmt.setInt(6, actor);

            if (stmt.executeUpdate() != 1)
                throw new Exception("Fehler beim Einfügen des MovieCharacter-Datensatzes");
        }


        this.movCharID = id;
    }


}
