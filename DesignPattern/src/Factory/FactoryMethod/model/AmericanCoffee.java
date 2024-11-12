package Factory.FactoryMethod.model;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Factory.FactoryBefore
 * @className Factory.FactoryBefore.AmericanCoffee
 * @date 2024/10/22 17:06
 * @description 美式咖啡 子类
 */
public class AmericanCoffee extends Coffee {
    @Override
    public String getName() {
        return "美式咖啡";
    }
}
