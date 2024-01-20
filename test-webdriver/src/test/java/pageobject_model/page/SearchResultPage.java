package pageobject_model.page;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.time.Duration;
import java.util.List;

public class SearchResultPage {
    private WebDriver driver;
    private String searchTerm;


    SearchResultPage (WebDriver driver, String searchTerm){
        this.driver = driver;
        this.searchTerm=searchTerm;
        PageFactory.initElements(driver, this);
    }

    public int countResultNumberInSearchTerm(){
        new WebDriverWait(driver, Duration.ofSeconds(10))
                .until(ExpectedConditions.presenceOfElementLocated(By.xpath("//*[@id=\"rcnt\"]")));
        List<WebElement> searchResult = driver.findElements(By.xpath("//*[@id=\"rso\"]/*"));
        System.out.println("Size of result is "+searchResult.size());
        return searchResult.size();
    }

}
