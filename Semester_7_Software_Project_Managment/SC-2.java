import javax.servlet.http.*;
import java.sql.*;
import java.util.logging.Level;

public class TestMe extends AbstractTestCaseServlet
{
    private boolean bzdPrivate = false;

    public void bzd(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        bzdPrivate = true;
        data = bzd_source(request, response);

        Connection dBConnection = IO.getDBConnection();
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        int id = 0;
        try
        {
            id = Integer.parseInt(data);
        }
        catch ( NumberFormatException nfx )
        {
            id = -1; 
        }

        try
        {
            preparedStatement = dBConnection.prepareStatement("select * from invoices where uid=?");
            preparedStatement.setInt(1, id);

            resultSet = preparedStatement.executeQuery();
            
            IO.writeString("bzd() - result requested: " + data +"\n");
        }
        catch (SQLException exceptSql)
        {
            IO.logger.log(Level.WARNING, "Error executing query", exceptSql);
        }
        finally
        {
            try
            {
                if (resultSet != null)
                {
                    resultSet.close();
                }
            }
            catch (SQLException exceptSql)
            {
                IO.logger.log(Level.WARNING, "Could not close ResultSet", exceptSql);
            }

            try
            {
                if (preparedStatement != null)
                {
                    preparedStatement.close();
                }
            }
            catch (SQLException exceptSql)
            {
                IO.logger.log(Level.WARNING, "Could not close PreparedStatement", exceptSql);
            }

            try
            {
                if (dBConnection != null)
                {
                    dBConnection.close();
                }
            }
            catch (SQLException exceptSql)
            {
                IO.logger.log(Level.WARNING, "Could not close Connection", exceptSql);
            }
        }

    }

    private String bzd_source(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        if (bzdPrivate)
        {
            
            data = request.getParameter("id");
        }
        else
        {
            
            data = null;
        }

        return data;
    }

 
    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
