package pageobject_model.test;

import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.testng.Assert;
import org.testng.annotations.AfterTest;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.Test;
import pageobject_model.page.SeleniumHQHomePage;

import java.time.Duration;
import java.util.List;

public class WebDriverSeleniumHQTest {
    private  WebDriver driver;
    @BeforeTest (alwaysRun = true)
    public void browserSetup(){
        driver = new ChromeDriver();
    }
    @Test
     public void commonSearchResultTest () {
        int expectedSearchResultsNumber = new SeleniumHQHomePage(driver)
                .openPage()
                .searchForTerms("Something")
                .countResultNumberInSearchTerm();
        Assert.assertTrue(expectedSearchResultsNumber>0, "Search result are empty");
    }

    @AfterTest(alwaysRun = true)
    public void browserClose(){
        driver.quit();
        driver=null;
    }

}
