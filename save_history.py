import argparse
import gspread
from datetime import datetime
import os

def main(args):
    commit_message: str = args.commit_message
    problem_number, duration = commit_message.split("/")
    problem_number = int(problem_number)
    commit_number = args.commit_number        
    user_name = args.user_name
    site_address = f"https://www.acmicpc.net/problem/{problem_number}"
    commit_address = f"https://github.com/Sungijnwoo/Coding-Test/commit/{commit_number}"
    duration = float(duration)
    current_time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    gc = gspread.service_account(filename='google-services.json') # 수정됨
    sheet = gc.open_by_url('https://docs.google.com/spreadsheets/d/1k4sifuVCdUsaR_apfofK0gXaFud0UwjMoL-3xj1NwJE/edit#gid=0')
    worksheet = sheet.worksheet("history") # 이름으로 워크시트 선택
    start_row = len(worksheet.col_values(1)) + 1
    worksheet.update_cell(start_row, 1, user_name)
    worksheet.update_cell(start_row, 2, site_address)
    worksheet.update_cell(start_row, 3, commit_address)
    worksheet.update_cell(start_row, 4, f"{duration}")
    worksheet.update_cell(start_row, 5, current_time)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("user_name", type=str)
    parser.add_argument("commit_message", type=str)
    parser.add_argument("commit_number", type=str)
    args = parser.parse_args()
    main(args)

    