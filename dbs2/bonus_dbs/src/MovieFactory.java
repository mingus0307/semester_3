import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class MovieFactory {

    public static Movie findById(long id) throws SQLException {
        String sql = "SELECT movie_id, title, year, type FROM movie WHERE movie_id = ?";
        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql)) {
            stmt.setLong(1, id);
            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) {
                    Movie movie = new Movie();
                    movie.setMovieID(rs.getInt("movie_id"));
                    movie.setTitle(rs.getString("title"));
                    movie.setYear(rs.getInt("year"));
                    movie.setType(rs.getString("type"));
                    return movie;
                } else {
                    return null;
                }
            }
        }
    }

    public static List<Movie> findByTitle(String title) throws SQLException {
        String sql = "SELECT movie_id, title, year, type FROM movie WHERE title ILIKE ?";
        List<Movie> movies = new ArrayList<>();

        try (PreparedStatement stmt = DBConnection.getConnection().prepareStatement(sql)) {
            stmt.setString(1, "%" + title + "%");  // Teilstring-Suche
            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {
                    Movie movie = new Movie();
                    movie.setMovieID(rs.getInt("movie_id"));
                    movie.setTitle(rs.getString("title"));
                    movie.setYear(rs.getInt("year"));
                    movie.setType(rs.getString("type"));
                    movies.add(movie);
                }
            }
        }

        return movies;
    }
}
