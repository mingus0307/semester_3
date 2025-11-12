import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.List;

public class Main {
    public static void testInsert() throws Exception {
        boolean ok = false;
        try {
            Person person = new Person();
            person.setName("Karl Tester");
            person.insert();

            Movie movie = new Movie();
            movie.setTitle("Die tolle Komoedie");
            movie.setYear(2012);
            movie.setType("C");
            movie.insert();

            MovieCharacter chr = new MovieCharacter();
            chr.setMovie(movie.getMovieID());
            chr.setActor(person.getPerson_id());
            chr.setCharacter("Hauptrolle");

            chr.setAlias(null);
            chr.setPosition(1);
            chr.insert();

            Genre genre = new Genre();
            genre.setGenre("Unklar");
            genre.insert();

            MovieGenre movieGenre = new MovieGenre();
            movieGenre.setGenre(genre.getGenreID());
            movieGenre.setMovie(movie.getMovieID());
            movieGenre.insert();

            DBConnection.getConnection().commit();
            } catch (Exception e) {
            DBConnection.getConnection().rollback();
            throw e;
            }
        }

    public static void main(String[] args) throws Exception {
        DBConnection.open();
        testInsert();

        Movie found = MovieFactory.findById(1);
        if (found != null) {
            System.out.println(found.getTitle() + " (" + found.getYear() + ")");
        }

        List<Movie> list = MovieFactory.findByTitle("Komoedie");
        for (Movie m : list) {
            System.out.println("Treffer: " + m.getTitle());
        }

    }
}
