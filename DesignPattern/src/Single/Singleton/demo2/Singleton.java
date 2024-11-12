package Single.Singleton.demo2;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName DesignPattern
 * @package Single.Singleton.demo2
 * @className Single.Singleton.demo2.Single.Singleton
 * @date 2024/10/22 15:17
 * @description 静态代码实现
 */
public class Singleton {
    private Singleton(){

    }

    private static Singleton instance;

    //静态代码块进行赋值
    // 区别相似
    static {
        instance = new Singleton();
    }

    public static Singleton getInstance(){
        return instance;
    }
}
