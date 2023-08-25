import os

def replace_spaces_with_hyphens(folder_path):
    for filename in os.listdir(folder_path):
        if os.path.isfile(os.path.join(folder_path, filename)):
            new_filename = filename.replace(' ', '-')
            if new_filename != filename:
                old_path = os.path.join(folder_path, filename)
                new_path = os.path.join(folder_path, new_filename)
                os.rename(old_path, new_path)
                print(f'Renamed: {filename} -> {new_filename}')

if __name__ == "__main__":
    target_folder = "Monotonic-Stack"
    replace_spaces_with_hyphens(target_folder)