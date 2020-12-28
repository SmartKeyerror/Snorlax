# 统计某个文件中所有单词出现的次数，使用 shell 脚本实现
awk -F ' ' '{for(i=1;i<=NF;i=i+1){print $i}}' words.txt |sort|uniq -c|sort -nr|awk -F' ' '{printf("%s %s\n",$2,$1)}'