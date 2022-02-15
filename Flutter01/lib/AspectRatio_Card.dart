import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'ListData.dart';

class MyApp1 extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('xx Demo'),
        ),
        body: LayoutDemo(),
      ),
    );
  }
}

class LayoutDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return ListView(
        children: listData.map((value) {
      return Card(
        margin: EdgeInsets.all(10),
        child: Column(
          children: <Widget>[
            AspectRatio(
              aspectRatio: 20 / 9,
              child: Image.network(
                value['imageUrl'],
                fit: BoxFit.cover,
              ),
            ),
            ListTile(
              leading: CircleAvatar(
                backgroundImage: NetworkImage(value['imageUrl']),
              ),
              title: Text(value['title']),
              subtitle: Text(value['author'],maxLines: 2,overflow:TextOverflow .ellipsis,),
            )
          ],
        ),
      );
    }).toList());
  }
}
/*Card(
          margin: EdgeInsets.all(10),
          child: Column(
            children: <Widget>[
              AspectRatio(
                aspectRatio: 18 / 9,
                child: Image.network(
                  'https://www.itying.com/images/flutter/2.png',
                  fit: BoxFit.cover,
                ),
              ),
              ListTile(
                leading: ClipOval(
                  child: Image.network(
                    'https://www.itying.com/images/flutter/2.png',
                    fit: BoxFit.cover,
                    height: 50,
                    width: 50,
                  ),
                ),
                title: Text("xxxx"),
                subtitle: Text('................'),
              )
            ],
          ),
        )*/

/*class LayoutDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return ListView(
      children: [
        Card(
          margin: EdgeInsets.all(10),
          child: Column(
            children: <Widget>[
              ListTile(
                title: Text(
                  "张三",
                  style: TextStyle(fontSize: 28),
                ),
                subtitle: Text('av enginner'),
              ),
              ListTile(
                title: Text(
                  "电话: xxx",
                ),
              ),
              ListTile(
                title: Text(
                  "地址: xxxxxxxxxx",
                ),
              ),
            ],
          ),
        ), Card(
          margin: EdgeInsets.all(10),
          child: Column(
            children: <Widget>[
              ListTile(
                title: Text(
                  "张三",
                  style: TextStyle(fontSize: 28),
                ),
                subtitle: Text('av enginner'),
              ),
              ListTile(
                title: Text(
                  "电话: xxx",
                ),
              ),
              ListTile(
                title: Text(
                  "地址: xxxxxxxxxx",
                ),
              ),
            ],
          ),
        ), Card(
          margin: EdgeInsets.all(10),
          child: Column(
            children: <Widget>[
              ListTile(
                title: Text(
                  "张三",
                  style: TextStyle(fontSize: 28),
                ),
                subtitle: Text('av enginner'),
              ),
              ListTile(
                title: Text(
                  "电话: xxx",
                ),
              ),
              ListTile(
                title: Text(
                  "地址: xxxxxxxxxx",
                ),
              ),
            ],
          ),
        ),
      ],
    );
  }
}*/

/*class LayoutDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return AspectRatio(
      aspectRatio: 2.0 / 1.0,
      child: Container(
        color: Colors.blue,
      ),
    );
  }
}*/
