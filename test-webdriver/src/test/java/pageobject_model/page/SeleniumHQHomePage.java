package pageobject_model.page;

import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.time.Duration;
import java.util.List;

public class SeleniumHQHomePage {
    private static final String HOMEPAGE_URL = "https://www.google.com/";
    private WebDriver driver;
    @FindBy(xpath = "//*[@id=\"APjFqb\"]")
    private WebElement searchInput;

    public SeleniumHQHomePage(WebDriver driver) {
        this.driver = driver;
        PageFactory.initElements(driver, this);
    }

    public SeleniumHQHomePage openPage() {
        driver.get(HOMEPAGE_URL);
        new WebDriverWait(driver, Duration.ofSeconds(10))
                .until(ExpectedConditions.presenceOfElementLocated(By.xpath("//*[@id=\"APjFqb\"]")));
        return this;
    }
    
    public SearchResultPage searchForTerms (String term){
        searchInput.sendKeys(term + Keys.ENTER);
        return new SearchResultPage(driver, term);
    }
}

