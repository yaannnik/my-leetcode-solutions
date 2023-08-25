import re

def update_link_names_in_md_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    updated_content = content
    link_pattern = r'\[([^]]+)\]\(([^)]+)\)'
    matches = re.findall(link_pattern, content)

    for match in matches:
        display_text, url = match
        last_slash_index = url.rfind('/')
        last_dot_index = url.rfind('.')
        if last_slash_index != -1 and last_dot_index != -1 and last_slash_index < last_dot_index:
            new_display_text = url[last_slash_index + 1:last_dot_index]
            updated_content = updated_content.replace(f'[{display_text}]({url})', f'[{new_display_text}]({url})')

    with open(file_path, 'w') as file:
        file.write(updated_content)

if __name__ == "__main__":
    target_file = "README.md"
    update_link_names_in_md_file(target_file)
