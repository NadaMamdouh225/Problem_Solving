int str_to_int(string s)
{
    int h1 = s[0] - '0';
    int h2 = s[1] - '0';
    return (h1*10) + h2;
}

string int_to_string(int x)
{
    string s = to_string(x);
    if(s.length()<2)
        s = "0" + s;
        return s;
}
string timeConversion(string s) {
    int hours;
    string store_hours;
    string new_s;
    if(s[s.length()-2] == 'A')
    {
        hours = str_to_int(s.substr(0,2));
        if(hours == 12)
            hours = 0;
        store_hours = int_to_string(hours);
        new_s = store_hours + (s.substr(2,s.length()-4));
    }else if(s[s.length()-2] == 'P')
    {
        hours = str_to_int(s.substr(0,2));
        if(hours != 12)
            hours = 12 + hours;
        store_hours = int_to_string(hours);
        new_s = store_hours + (s.substr(2,s.length()-4));
    }
    return new_s;
}
