import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Person {
    private int person_id;
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPerson_id() {
        return person_id;
    }

    public void setPerson_id(int person_id) {
        this.person_id = person_id;
    }

    public void insert() throws Exception {
        int id;


        String sql = "SELECT nextval('person_id_seq') AS id";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {

            if (!rs.next())
                throw new Exception("Keine neue ID aus Sequenz erhalten");

            id = rs.getInt("id");
        }


        sql = "INSERT INTO person (person_id, name) VALUES (?, ?)";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql)) {
            stmt.setInt(1, id);
            stmt.setString(2, name);

            if (stmt.executeUpdate() != 1)
                throw new Exception("Fehler beim Einfügen der Person");
        }


        this.person_id = id;
    }

}
