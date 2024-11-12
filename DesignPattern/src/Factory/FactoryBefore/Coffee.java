package Factory.FactoryBefore;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Factory.FactoryBefore
 * @className Factory.FactoryBefore.Coffee
 * @date 2024/10/22 17:05
 * @description 咖啡类
 */
public class Coffee {
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void addSugar() {
        System.out.println("加糖");
    }

    public void addmilk() {
        System.out.println("加奶");
    }
}
