import argparse

def main(args):
    try:
        commit_message: str = args.commit_message
        problem_number, duration = commit_message.split("/")
        problem_number = int(problem_number)
        duration = float(duration)

        site_address = f"https://www.acmicpc.net/problem/{problem_number}"

        print(site_address, duration)
    except:
        print("commit message error")



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("commit_message", type=str)

    