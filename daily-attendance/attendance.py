import re
import os
import time
from collections import defaultdict

current_path = os.path.dirname(__file__)

ignore_files = ["README.md", "attendance.py", "attendance-date.md"]


basic_url = "https://github.com/SmartKeyerror/Snorlax/blob/master/daily-attendance"


def transform_timestamp(timestamp):
    return time.strftime("%Y-%m-%d", time.localtime(timestamp))


def get_files():
    attendance = defaultdict(list)

    for root, dirs, files in os.walk(current_path, topdown=False):

        root_url = f"{basic_url}/{root.split('/')[-1]}"

        for file in files:

            # 反正也没多少文件, 简单过滤下
            if file in ignore_files:
                continue

            # 放弃使用 ctime，改用 Hugo 日期 + title 的方式定义文件名称，re 解析时间即可

            match = re.search(r"(\d{4}-\d{1,2}-\d{1,2})", file)

            if not match:
                continue

            create_time = match.group()

            filename = file.split(".")[0]

            attendance[create_time].append({
                "filename": filename[len(create_time) + 1:],
                "filepath": root_url + f"/{file}"
            })

    return attendance


def write_markdown(attendance):
    filepath = os.path.join(current_path, "attendance-date.md")
    with open(filepath, "w") as f:

        f.write("Auto generated, do not edit this file \n")
        f.writelines("\n")

        for date in sorted(attendance):
            items = attendance[date]
            f.write(f"### {date}\n")
            for item in items:
                f.writelines(f"- [{item['filename']}]({item['filepath']})\n")
            f.writelines("\n")


if __name__ == "__main__":
    write_markdown(get_files())
