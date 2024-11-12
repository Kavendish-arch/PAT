package Factory.FactoryMethod.factory;

import Factory.FactoryMethod.model.Coffee;
import Factory.FactoryMethod.model.LatteCoffee;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Factory.FactoryMethod.factory
 * @className Factory.FactoryMethod.factory.LatteCoffeeFactory
 * @date 2024/10/22 17:34
 * @description 拿铁咖啡工厂
 */
public class LatteCoffeeFactory implements CoffeeFactory{
    @Override
    public Coffee createCoffee() {
        return new LatteCoffee();
    }
}
