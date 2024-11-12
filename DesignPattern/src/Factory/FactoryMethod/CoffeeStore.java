package Factory.FactoryMethod;

import Factory.FactoryMethod.factory.AmericanCoffeeFactory;
import Factory.FactoryMethod.factory.CoffeeFactory;
import Factory.FactoryMethod.model.Coffee;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Factory.FactoryBefore
 * @className Factory.FactoryBefore.CoffeeSotre
 * @date 2024/10/22 17:08
 * @description 咖啡店
 * 代表业务
 * 不需要太多修改
 */
public class CoffeeStore {
    private CoffeeFactory factory;

    public CoffeeStore(CoffeeFactory factory) {
        this.factory = factory;
    }

    public Coffee orderCoffee(String type) {
        Coffee coffee = factory.createCoffee();
        coffee.addSugar();
        coffee.addmilk();
        return coffee;
    }

    public static void main(String[] args) {

    }
}
