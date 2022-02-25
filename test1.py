#!/usr/bin/python3
import numpy
import jieba

# 读取文档内容
file = open("test.txt", encoding="utf-8")
content = file.read()
# print("文档内容：",content)

# 使用jieba分词库对文本内容进行分词
seg_list = jieba.cut(content, cut_all=False)
# print("Default Mode: " + "/ ".join(seg_list))
print(seg_list)

# 使用字典存储所有不同的单词，并统计词频
dist = {}
for word in seg_list:
    if word in dist:
        dist[word] += 1
    else:
        dist[word] = 1
print(dist)

# 输出dist内容至目标文件中
target = open("target.txt", "w", encoding="utf-8")
for k in dist.keys():
    print(k, dist[k])
    target.write(k+"\t"+str(dist[k])+"\n")

close(file)
close(target)