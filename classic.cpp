void TestString_Memory(const string &data,string &out_data) {
	cout << "data =  " << data << endl;
	cout<<"data.size()  "<<data.size() << endl;
	out_data.resize(2048);
	cout << "(long long)out_data.data() addr:  " << (long long)out_data.data() << endl;

}

int main()
{
	string str_one;
	str_one.resize(1024);
	auto data = const_cast<char*>(str_one.data());
	memset(data,'A', 5);
	cout<< str_one<<" \n" << sizeof(str_one) << endl;
	//TestString_Memory(str_one);

	string out_str;
	TestString_Memory(str_one, out_str);
	cout << str_one << " \n  sizeof(out_str) :" << sizeof(out_str) << endl;
	cout << "(long long)out_data.data() addr:  " << (long long)out_str.data() << endl;


	return 0;
}
