#include<bits/stdc++.h>
using namespace std;
int memory_limit,num_test_case;
double time_limit;
string name;
string title,description,input,output,sample_input,sample_output,hint;
string name_xml;
inline void init()
{
    cout<<"Please enter the title of the problem (English only, no space)"<<endl;
    cin>>name;
    cout<<"Please enter the time limit"<<endl;
    cin>>time_limit;
    cout<<"Please enter the memory_limit"<<endl;
    cin>>memory_limit;
    cout<<"Please enter the number of test cases"<<endl;
    cin>>num_test_case;
}

ifstream rh;
inline void read_title()
{
    string tmp;
    while(getline(rh,tmp))
    {
        bool flag=false;
        for(int i=0;i<tmp.size()-1;i++)
        {
            if(tmp[i]=='h'&&tmp[i+1]=='2')
            {
                //cout<<tmp<<endl<<endl;
                while(tmp[i]!='>') ++i;
                ++i;
                while(tmp[i]!='<')
                {
                    title.push_back(tmp[i]);
                    ++i;
                }
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
}
inline void read_description()
{
    string tmp;
    while(getline(rh,tmp))
    {
        if(tmp.size()>2&&tmp[1]=='h'&&tmp[2]=='3') break;
    }
    while(getline(rh,tmp))
    {
        if(tmp.size()>2&&tmp[1]=='h'&&tmp[2]=='3') break;
        description+=tmp;
        description+='\n';
    }
}
inline void read_input()
{
    string tmp;
    while(getline(rh,tmp))
    {
        if(tmp.size()>2&&tmp[1]=='h'&&tmp[2]=='3') break;
        input+=tmp;
        input+='\n';
    }
}
inline void read_output()
{
    string tmp;
    while(getline(rh,tmp))
    {
        if(tmp.size()>2&&tmp[1]=='h'&&tmp[2]=='3') break;
        output+=tmp;
        output+='\n';
    }
}
inline void read_sample_input()
{
    string tmp;
    while(getline(rh,tmp))
    {
        if(tmp.size()>2&&tmp[1]=='h'&&tmp[2]=='4') break;
    }
    while(getline(rh,tmp))
    {
        bool flag=true;
        if(tmp.size()>2&&tmp[1]=='h'&&tmp[2]=='4') break;
        if(tmp.size()>0&&tmp[0]=='<')
        {
            for(int i=0;i<tmp.size()-2;i++)
            {
                if(tmp[i]=='/'&&tmp[i+1]=='c'&&tmp[i+2]=='o') 
                {
                    flag=false;
                    break;
                }
                if(tmp[i]=='d'&&tmp[i+1]=='e'&&tmp[i+2]=='>')
                {
                    i+=3;
                    while(i<tmp.size())
                    {
                        sample_input.push_back(tmp[i]);
                        ++i;
                    }
                }
            }
        }
        else sample_input+=tmp;
        if(flag) sample_input+='\n';
    }
}
inline void read_sample_output()
{
    string tmp;
    while(getline(rh,tmp))
    {
        bool flag=true;
        if(tmp.size()>2&&tmp[1]=='h'&&tmp[2]=='3') break;
        if(tmp.size()>0&&tmp[0]=='<')
        {
            for(int i=0;i<tmp.size()-2;i++)
            {
                if(tmp[i]=='/'&&tmp[i+1]=='c'&&tmp[i+2]=='o') 
                {
                    flag=false;
                    break;
                }
                if(tmp[i]=='d'&&tmp[i+1]=='e'&&tmp[i+2]=='>')
                {
                    i+=3;
                    while(i<tmp.size())
                    {
                        sample_output.push_back(tmp[i]);
                        ++i;
                    }
                }
            }
        }
        else sample_output+=tmp;
        if(flag) sample_output+='\n';
    }
}
inline void read_hint()
{
    string tmp;
    while(getline(rh,tmp))
    {
        if(tmp.size()>3&&tmp[1]=='/'&&tmp[2]=='b'&&tmp[3]=='o') break;
        hint+=tmp;
        hint+='\n';
    }
}
inline void read_html()
{
    rh.open(name+".html");
    read_title();
    read_description();
    read_input();
    read_output();
    read_sample_input();
    read_sample_output();
    read_hint();
    rh.close();
}


ofstream wd;
inline void write_data()
{
    for(int i=1;i<=num_test_case;i++)
    {
        string i_s,filename;
        int tmp=i;
        while(tmp) i_s.push_back(tmp%10+48),tmp/=10;
        reverse(i_s.begin(),i_s.end());
        filename=name+i_s;

        wd<<R"(<test_input name=")";
        wd<<filename;
        wd<<R"("><![CDATA[)";
        ifstream inputdata(filename+".in");
        string tmp1;
        while(getline(inputdata,tmp1))
        {
            wd<<tmp1<<endl;
        }
        inputdata.close();

        wd<<R"(]]></test_input>
<test_output name=")";
        wd<<filename;
        wd<<R"("><![CDATA[)";
        ifstream outputdata(filename+".out");
        while(getline(outputdata,tmp1))
        {
            wd<<tmp1<<endl;
        }
        outputdata.close();
        wd<<R"(]]></test_output>)"<<endl;
    }
}
inline void write_xml()
{
    wd.open(name_xml);
    wd<<R"(<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE fps PUBLIC 
"-//freeproblemset//An opensource XML standard for Algorithm Contest Problem Set//EN"
"http://hustoj.com/fps.current.dtd" >

<fps version="1.4" url="https://github.com/zhblue/freeproblemset/">
<generator name="mip001" url="https://mip001.jdoi.top" />

<item>
    <title><![CDATA[)";
    wd<<title;
    wd<<R"(]]></title>
    <time_limit unit="s"><![CDATA[)";
    wd<<time_limit;
    wd<<R"(]]></time_limit>

    <memory_limit unit="mb"><![CDATA[)";
    wd<<memory_limit;
    wd<<R"(]]></memory_limit>

    
    <description><![CDATA[)";
    wd<<description;
    wd<<R"(]]></description>
    <input><![CDATA[)";
    wd<<input;
    wd<<R"(]]></input> 
    <output><![CDATA[)";
    wd<<output;
    wd<<R"(]]></output>
    <sample_input><![CDATA[)";
    wd<<sample_input;
    wd<<R"(]]></sample_input>
    <sample_output><![CDATA[)";
    wd<<sample_output;
    wd<<R"(]]></sample_output>)"<<endl;
    
    write_data();

    wd<<R"(<hint><![CDATA[)";
    wd<<hint;
    wd<<R"(]]></hint>)"<<endl;
    wd<<R"(</item>

</fps>)";
    wd.close();
}


int main()
{
    init();
    read_html();
    name_xml=name+".xml";
    write_xml();
    return 0;
}