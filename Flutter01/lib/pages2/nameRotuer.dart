import 'dart:ffi';

import 'package:flutter/material.dart';
import '../pages/Tabs.dart';
import '../pages/Form.dart';
import '../pages/Search.dart';

class MyApp extends StatelessWidget {
  final routes = {
    '/form': (context) => FormPage(),
    '/Search': (context,{arguments}) => SearchPager(arguments:arguments),
  };

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        home: MyApp1(),
        onGenerateRoute: (RouteSettings settings) {
          final String? name = settings.name;
          final Function pageContentBuilder = this.routes[name] as Function;
          if (pageContentBuilder != nullptr) {
            if (settings != nullptr) {
              final Route route = MaterialPageRoute(
                  builder: (context) => pageContentBuilder(context,
                      arguments: settings.arguments));
              return route;
            } else {
              final Route route = MaterialPageRoute(
                  builder: (context) => pageContentBuilder(context));
              return route;
            }
          }
        });
  }
}

class ScreenArguments {
  final String title;
  final String message;

  ScreenArguments(this.title, this.message);
}

class PassArgumentsScreen extends StatelessWidget {
  static const routeName = '/passArguments';

  final String title;
  final String message;

  // This Widget accepts the arguments as constructor
  // parameters. It does not extract the arguments from
  // the ModalRoute.
  //
  // The arguments are extracted by the onGenerateRoute
  // function provided to the MaterialApp widget.
  const PassArgumentsScreen({
    Key? key,
    required this.title,
    required this.message,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(title),
      ),
      body: Center(
        child: Text(message),
      ),
    );
  }
}
