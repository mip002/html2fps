# html2fps
Convert HTML to an fps file
# html2fps 

[简体中文]([html2fps/README_CN.md at main · mip002/html2fps (github.com)](https://github.com/mip002/html2fps/blob/main/README_CN.md))

Tool for easily converting HTML files to FPS.XML files 

## What can it do? 

This is a tool that can easily convert HTML files to FPS.XML files It can convert HTML files to FPS.XML. If you are used to writing problems using Typora, but some OJs only support uploading problems using FPS.XML, you can use this tool. 

## How to use it? 

This tool is very easy to use, but you still need to follow the following steps to use it: 

1. Write your problems on Typora as usual, but there are some minor formatting requirements: 

   - Please use the second-level heading (##) for the title. 

   - The following is the 5 sections: title description, input format, output format, input and output examples, and instructions / tips. Please use level three titles (###) for these sections. It should be noted that the above names are only used for explanation purposes and can be freely named, but should ensure that there are a total of 5 sections in order.
   - The Input and Output sample section includes two sub-sections: input and output. Please use four-level titles (####) for these section titles; It should be noted that the above names are only used for explanation purposes and can be freely named, but it should be ensured that there are a total of 2 sections in order. 
   - In addition, please do not use the title line separately!

2. Select `File> Export> HTML (without styles)` to export. The file name must be in English without spaces. 

3. Construct the data as usual, but change the file name to HTML file name + test point numbers .in and .out. The test point numbers should be consecutively incremented from 1 (such as test1.in and test1.out). 

4. After compiling main.cpp, move the executable file to the target folder and run it. 

5. the program will ask you a total of 4 questions, which are: 

   1. Problem name: You need to enter the name of the HTML file without a suffix (such as test). 
   2. Time limit (s): Set according to the time limit you specify. 
   3. Memory limit (MB): Set according to the memory limit you specified. 
   4. Test point: You need to enter the number of test points you have set. The program will try to find them starting from test point 1. Please do not enter a number larger than the total number of test points in the folder. 

6. Next you need to wait... and then it's done! An XML file will be created in your folder, and that's it!

## Q&A

Q: If I don't use Typora as a Markdown editor, can I use this tool?

A: It is recommended to use Typora, as different editors may cause differences and cause the program to fail.

Q: If I just don't want to use Typora, is there any way to use this tool?

A: We have provided an example of an HTML file. If you insist on using another editor, you can compare and modify the format of the HTML file with the sample after it has been exported, but this will reduce your efficiency and result in higher errors, so we do not recommend this practice. Similarly, if you prefer to use HTML, you can also write in the sample format.
