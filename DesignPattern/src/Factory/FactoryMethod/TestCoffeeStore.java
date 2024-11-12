package Factory.FactoryMethod;

import Factory.FactoryMethod.factory.AmericanCoffeeFactory;
import Factory.FactoryMethod.factory.CoffeeFactory;
import Factory.FactoryMethod.model.Coffee;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Factory.FactoryBefore
 * @className Factory.FactoryBefore.TestCoffeeStore
 * @date 2024/10/22 17:10
 * @description 测试咖啡店类
 */
public class TestCoffeeStore {
    public static void main(String[] args) {
        CoffeeFactory factory = new AmericanCoffeeFactory();
        CoffeeStore coffeeStore = new CoffeeStore(factory);

        Coffee coffee = coffeeStore.orderCoffee("latte");
        System.out.println(coffee.getName());

    }
}
