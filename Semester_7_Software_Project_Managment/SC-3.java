import javax.servlet.http.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.security.SecureRandom;
import java.io.IOException;
import java.util.logging.Level;

public class TestThis extends AbstractTestCase
{
    private static final boolean PRIVATE_STATIC_FINAL_TRUE = true;
    private static final boolean PRIVATE_STATIC_FINAL_FALSE = false;

    public void bwd() throws Throwable
    {
        int data;
		String stringIntValue = "";
        int x = (new SecureRandom()).nextInt(3);
            switch (x)
            {
            case 0:
                stringIntValue = "0";
                break;
            case 1:
                stringIntValue = "1";
            break;
                
            }
            IO.writeLine(stringIntValue);
			
        if (PRIVATE_STATIC_FINAL_TRUE)
        {
            data = Integer.MIN_VALUE; 
            {
                InputStreamReader readerInputStream = null;
                BufferedReader readerBuffered = null;
                
                try
                {
                    readerInputStream = new InputStreamReader(System.in, "UTF-8");
                    readerBuffered = new BufferedReader(readerInputStream);                    
                    String stringNumber = readerBuffered.readLine();
                    if (stringNumber != null) 
                    {
						
                        try
                        {
                            data = Integer.parseInt(stringNumber.trim());
                        }
                        catch(NumberFormatException exceptNumberFormat)
                        {
                            IO.logger.log(Level.WARNING, "Number format exception parsing data from string", exceptNumberFormat);
                        }
                    }
                }
                catch (IOException exceptIO)
                {
                    IO.logger.log(Level.WARNING, "Error with stream reading", exceptIO);
                }
                finally
                {
                    try
                    {
                        if (readerBuffered != null)
                        {
                            readerBuffered.close();
                        }
                    }
                    catch (IOException exceptIO)
                    {
                        IO.logger.log(Level.WARNING, "Error closing BufferedReader", exceptIO);
                    }

                    try
                    {
                        if (readerInputStream != null)
                        {
                            readerInputStream.close();
                        }
                    }
                    catch (IOException exceptIO)
                    {
                        IO.logger.log(Level.WARNING, "Error closing InputStreamReader", exceptIO);
                    }
                }
            }
           
        else
        {
             data = 0;
        }

        if (PRIVATE_STATIC_FINAL_TRUE)
        {
           IO.writeLine("bwd: 100/" + data + " = " + (100 / data) + "\n");
        }
    }

    
    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
