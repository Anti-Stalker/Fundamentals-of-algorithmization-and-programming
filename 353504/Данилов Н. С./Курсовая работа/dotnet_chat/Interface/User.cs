using (SqlConnection connection = new SqlConnection(connectionString))
{
    connection.Open();

    string query = "SELECT * FROM users WHERE name = @name";
    SqlCommand command = new SqlCommand(query, connection);
    command.Parameters.AddWithValue("@name", "exampleName");

    using (SqlDataReader reader = command.ExecuteReader())
    {
        if (reader.Read())
        {
            int id = reader.GetInt32(reader.GetOrdinal("id"));
            string name = reader.GetString(reader.GetOrdinal("name"));
            // Обработка полученных данных
            Console.WriteLine($"User ID: {id}, Name: {name}");
        }
    }
}﻿
namespace Common
{
    public class User
    {
        public string username { get; set; }
    }
}
