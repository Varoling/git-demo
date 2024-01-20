package first_test;

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
        driver.get("https://www.google.com/");
//        new WebDriverWait(driver, Duration.ofSeconds(10))
//                .until(ExpectedConditions.presenceOfElementLocated(By.xpath("//*[@id=\"APjFqb\"]")));
        WebElement searchInput = waitForElement(driver,By.xpath("//*[@id=\"APjFqb\"]"));
        searchInput.sendKeys("Something" + Keys.ENTER);
        new WebDriverWait(driver, Duration.ofSeconds(10))
                .until(ExpectedConditions.presenceOfElementLocated(By.xpath("//*[@id=\"rcnt\"]")));
        List<WebElement> searchResult = driver.findElements(By.xpath("//*[@id=\"rso\"]/*"));
        System.out.println(searchResult.size());
        Assert.assertTrue(searchResult.size()>0, "Search result are empty");
    }

    @AfterTest(alwaysRun = true)
    public void browserClose(){
        driver.quit();
        driver=null;
    }
    private static WebElement waitForElement(WebDriver driver, By by) {
        return new WebDriverWait(driver, Duration.ofSeconds(10))
                .until(ExpectedConditions.presenceOfElementLocated(by));
    }

}
