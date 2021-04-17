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

            filename, _ = file.split(".")

            # 严格意义上来讲, ctime 并不一定是该文件的创建时间, 当文件内容修改时, 其值也会发生改变
            ctime = os.path.getctime(os.path.join(root, file))

            ctime_datetime = transform_timestamp(ctime)

            attendance[ctime_datetime].append({
                "filename": filename,
                "filepath": root_url + f"/{file}"
            })

    return attendance


def write_markdown(attendance):
    with open("attendance-date.md", "w") as f:
        for date in sorted(attendance):
            items = attendance[date]
            f.write(f"### {date}\n")
            for item in items:
                f.writelines(f"- [{item['filename'][4:]}]({item['filepath']})\n")
            f.writelines("\n")


if __name__ == "__main__":
    write_markdown(get_files())
