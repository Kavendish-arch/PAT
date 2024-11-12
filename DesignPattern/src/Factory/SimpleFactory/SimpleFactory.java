package Factory.SimpleFactory;

import Factory.SimpleFactory.model.AmericanCoffee;
import Factory.SimpleFactory.model.Coffee;
import Factory.SimpleFactory.model.LatteCoffee;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Factory.FactoryBefore.Factory
 * @className Factory.FactoryBefore.Factory.SimpleFacotry
 * @date 2024/10/22 17:18
 * @description 简单工厂模式
 */
public class SimpleFactory {


    public static Coffee orderCoffee(String type)
    {
        Coffee coffee = null;
        if ("american".equals(type))
        {
            // 依赖子类， 开闭原则
            coffee = new AmericanCoffee();
        }
        else if ("latte".equals(type))
        {
            coffee = new LatteCoffee();
        }
        else {
            System.out.println("对不起，您所点的咖啡没有");
        }
        return coffee;
    }
}
