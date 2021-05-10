
find({})
1. 查询所有数据。 如要查询所有数据值，则直接使用下面两种写法的任意一种即可： 
db.getCollection('example_data_1').find() 
db.getCollection('example_data_1').find({}) 
2. 查询特定数据如要查询某个或者某些具体字段，则可以使用下面的语法来查询。
如果有多个字段，则这些字段需要同时满足。
例如，对于数据集 example_data_1，要查询所有“age”字段为25的记录
db.getCollection('example_data_1').find({'age': 25}) 

3. 查询范围值数据 如要查询的字段值能够比较大小，则查询时可以限定值的范围。
例如，对数据集example_data_1，要查询所有“age”字段不小于25的记录， 则需要使用大于等于操作符“$gte”。查询语句如下：
db.getCollection('example_data_1').find({'age': {'$gte': 25}}) 
$gt >
$gte >= 
$lt <
$lte <=
$ne != 