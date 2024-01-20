import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.time.Duration;
import java.util.List;

public class HelloWebDriver {
    public static void main(String[] args) throws InterruptedException {
        WebDriver driver = new ChromeDriver();

        driver.get("https://www.google.com/");
//        new WebDriverWait(driver, Duration.ofSeconds(10))
//                .until(ExpectedConditions.presenceOfElementLocated(By.xpath("//*[@id=\"APjFqb\"]")));
        WebElement searchInput = waitForElement(driver,By.xpath("//*[@id=\"APjFqb\"]"));
        searchInput.sendKeys("Something" + Keys.ENTER);
        new WebDriverWait(driver, Duration.ofSeconds(10))
                .until(ExpectedConditions.presenceOfElementLocated(By.xpath("//*[@id=\"rcnt\"]")));
        List<WebElement> searchResult = driver.findElements(By.xpath("//*[@id=\"rso\"]/*"));
        System.out.println(searchResult.size());
        driver.quit();
    }

    private static WebElement waitForElement(WebDriver driver, By by) {
        return new WebDriverWait(driver, Duration.ofSeconds(10))
                .until(ExpectedConditions.presenceOfElementLocated(by));
    }
}
