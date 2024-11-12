package Factory.FactoryMethod.factory;

import Factory.FactoryMethod.model.AmericanCoffee;
import Factory.FactoryMethod.model.Coffee;
import Factory.FactoryMethod.model.LatteCoffee;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Factory.FactoryBefore.Factory
 * @className Factory.FactoryBefore.Factory.SimpleFacotry
 * @date 2024/10/22 17:18
 * @description 工厂方法模式
 */
public class AmericanCoffeeFactory implements CoffeeFactory{

    public Coffee createCoffee(){
            return new AmericanCoffee();
    }



}
