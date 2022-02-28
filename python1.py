#!/usr/bin/python3
from fileinput import filename
import jieba

# 读取文档内容
file_name = input("请输入文档名：")
with open(file_name, encoding="utf-8") as file:
    content = file.read()
# print("文档内容：",content)

# 使用jieba分词库对文本内容进行分词
seg_list = jieba.cut(content, cut_all=False)
# print("Default Mode: " + "/ ".join(seg_list))
print(seg_list)

# 使用字典存储所有不同的单词，并统计词频
dict = {}
for word in seg_list:
    if word in dict:
        dict[word] += 1
    else:
        dict[word] = 1
print(dict)

# 输出dist内容至目标文件中
with open("target.txt", "w", encoding="utf-8") as target:
    for k in dict:
        print(k, dict[k])
        target.write(k+"\t"+str(dict[k])+"\n")
