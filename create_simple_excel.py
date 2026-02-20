import os
import re
import csv

def analyze_program_content(file_path):
    """Analyze program content to determine data structure type and description"""
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Determine data structure type based on content
        data_structure = "Basic"
        description = "Basic program"
        
        # Check for different data structures
        if 'struct node' in content or 'class node' in content:
            if 'prev' in content:
                data_structure = "Doubly Linked List"
                description = "Doubly linked list implementation"
            else:
                data_structure = "Singly Linked List"
                description = "Singly linked list implementation"
        elif 'Array' in content or 'arr[]' in content or 'int Arr' in content:
            data_structure = "Array"
            description = "Array operations"
        elif 'Stack' in content or 'stack' in content:
            data_structure = "Stack"
            description = "Stack implementation"
        elif 'Queue' in content or 'queue' in content:
            data_structure = "Queue"
            description = "Queue implementation"
        elif 'Tree' in content or 'tree' in content or 'Binary' in content:
            data_structure = "Tree"
            description = "Tree data structure"
        elif 'Hashtable' in content or 'HashMap' in content or 'Map' in content:
            data_structure = "Hash Table"
            description = "Hash table implementation"
        elif 'String' in content or 'string' in content or 'str' in content:
            data_structure = "String"
            description = "String manipulation"
        elif 'malloc' in content or 'free' in content or 'new ' in content:
            data_structure = "Dynamic Memory"
            description = "Dynamic memory allocation"
        elif 'file' in content or 'File' in content or 'open(' in content:
            data_structure = "File Handling"
            description = "File operations"
        elif 'printf' in content and 'scanf' in content and len(content) < 500:
            data_structure = "Basic Input/Output"
            description = "Basic input output operations"
        elif 'main()' in content and len(content) < 300:
            data_structure = "Basic Program"
            description = "Basic program structure"
        elif 'Addition' in content or 'add' in content or '+' in content:
            data_structure = "Arithmetic"
            description = "Arithmetic operations"
        elif 'for(' in content or 'while(' in content:
            data_structure = "Looping"
            description = "Looping constructs"
        elif 'if(' in content or 'else' in content:
            data_structure = "Conditional"
            description = "Conditional statements"
        
        # Look for specific function names to refine description
        if 'InsertFirst' in content or 'InsertLast' in content:
            description = "Linked list insertion operations"
        elif 'DeleteFirst' in content or 'DeleteLast' in content:
            description = "Linked list deletion operations"
        elif 'Display' in content:
            description = f"{data_structure} display operations"
        elif 'Count' in content:
            description = f"{data_structure} counting operations"
        elif 'Reverse' in content:
            description = f"{data_structure} reversal operations"
        elif 'Search' in content or 'search' in content:
            description = f"{data_structure} searching operations"
        elif 'Sort' in content or 'sort' in content:
            description = f"{data_structure} sorting operations"
        
        return data_structure, description
        
    except Exception as e:
        return "Unknown", "Unable to read file"

def main():
    # Directory containing programs
    program_dir = r"c:\Users\dell\Desktop\LB\Data_Structures"
    
    # Lists to store program information
    program_data = []
    
    # Get all program files
    program_files = []
    for file in os.listdir(program_dir):
        if file.startswith('program') and (file.endswith('.c') or file.endswith('.java') or file.endswith('.js') or file.endswith('.cpp')):
            program_files.append(file)
    
    # Sort files by program number
    program_files.sort(key=lambda x: int(re.search(r'program(\d+)', x).group(1)))
    
    # Analyze each program
    prev_data_structure = None
    for file in program_files:
        file_path = os.path.join(program_dir, file)
        
        # Extract program number
        match = re.search(r'program(\d+)', file)
        if match:
            prog_num = int(match.group(1))
        else:
            prog_num = 0
        
        # Get file extension for language
        if file.endswith('.c'):
            language = 'C'
        elif file.endswith('.java'):
            language = 'Java'
        elif file.endswith('.js'):
            language = 'JavaScript'
        elif file.endswith('.cpp'):
            language = 'C++'
        else:
            language = 'Unknown'
        
        # Get file size
        file_size = os.path.getsize(file_path)
        
        # Analyze content
        data_structure, description = analyze_program_content(file_path)
        
        # Check similarity with previous program
        similarity = ""
        if prev_data_structure and prev_data_structure == data_structure:
            similarity = "Similar to previous program - same data structure"
        
        # Store information
        program_data.append([
            prog_num,
            file,
            language,
            data_structure,
            description,
            file_size,
            similarity
        ])
        
        prev_data_structure = data_structure
    
    # Create CSV file (can be opened in Excel)
    with open('Data_Structures_Programs.csv', 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        
        # Write header
        writer.writerow(['Program Number', 'Program Name', 'Language', 'Data Structure', 'Description', 'File Size (bytes)', 'Similarity Note'])
        
        # Write data
        for row in program_data:
            writer.writerow(row)
    
    # Create a summary
    data_structure_counts = {}
    for row in program_data:
        ds = row[3]
        if ds not in data_structure_counts:
            data_structure_counts[ds] = []
        data_structure_counts[ds].append(row[1])  # Add program name
    
    # Create summary CSV
    with open('Data_Structures_Summary.csv', 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        
        # Write header
        writer.writerow(['Data Structure', 'Count', 'Sample Programs', 'Color Code'])
        
        # Define colors for each data structure
        colors = {
            'Singly Linked List': '#FF6B6B',
            'Doubly Linked List': '#4ECDC4',
            'Array': '#45B7D1',
            'Stack': '#96CEB4',
            'Queue': '#FFEAA7',
            'Tree': '#DDA0DD',
            'Hash Table': '#98D8C8',
            'String': '#F7DC6F',
            'Dynamic Memory': '#BB8FCE',
            'File Handling': '#85C1E2',
            'Basic Input/Output': '#F8B739',
            'Basic Program': '#52B788',
            'Arithmetic': '#F72585',
            'Looping': '#7209B7',
            'Conditional': '#560BAD',
            'Unknown': '#CCCCCC'
        }
        
        # Write data sorted by count
        sorted_structures = sorted(data_structure_counts.items(), key=lambda x: len(x[1]), reverse=True)
        
        for ds, programs in sorted_structures:
            sample_programs = ', '.join(programs[:3])  # First 3 programs
            if len(programs) > 3:
                sample_programs += f" ... and {len(programs) - 3} more"
            
            color = colors.get(ds, '#FFFFFF')
            writer.writerow([ds, len(programs), sample_programs, color])
    
    print(f"CSV files created successfully!")
    print(f"Main file: 'Data_Structures_Programs.csv'")
    print(f"Summary file: 'Data_Structures_Summary.csv'")
    print(f"Total programs analyzed: {len(program_data)}")
    print(f"Unique data structures: {len(data_structure_counts)}")
    print("\nData Structure Summary:")
    for ds, programs in sorted_structures:
        print(f"  {ds}: {len(programs)} programs")
    
    # Create a simple HTML file with colors for better visualization
    html_content = """
<!DOCTYPE html>
<html>
<head>
    <title>Data Structures Programs</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        table { border-collapse: collapse; width: 100%; margin-bottom: 20px; }
        th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }
        th { background-color: #f2f2f2; }
        .color-box { width: 20px; height: 20px; display: inline-block; margin-right: 10px; }
    </style>
</head>
<body>
    <h1>Data Structures Programs Summary</h1>
    <table>
        <tr>
            <th>Color</th>
            <th>Data Structure</th>
            <th>Count</th>
            <th>Sample Programs</th>
        </tr>
"""
    
    for ds, programs in sorted_structures:
        color = colors.get(ds, '#FFFFFF')
        sample_programs = ', '.join(programs[:3])
        if len(programs) > 3:
            sample_programs += f" ... and {len(programs) - 3} more"
        
        html_content += f"""
        <tr>
            <td><span class="color-box" style="background-color: {color};"></span></td>
            <td>{ds}</td>
            <td>{len(programs)}</td>
            <td>{sample_programs}</td>
        </tr>
"""
    
    html_content += """
    </table>
    
    <h2>All Programs</h2>
    <table>
        <tr>
            <th>Program Number</th>
            <th>Program Name</th>
            <th>Language</th>
            <th>Data Structure</th>
            <th>Description</th>
            <th>File Size (bytes)</th>
            <th>Similarity Note</th>
        </tr>
"""
    
    for row in program_data:
        color = colors.get(row[3], '#FFFFFF')
        html_content += f"""
        <tr style="background-color: {color}33;">
            <td>{row[0]}</td>
            <td>{row[1]}</td>
            <td>{row[2]}</td>
            <td>{row[3]}</td>
            <td>{row[4]}</td>
            <td>{row[5]}</td>
            <td>{row[6]}</td>
        </tr>
"""
    
    html_content += """
    </table>
</body>
</html>
"""
    
    with open('Data_Structures_Programs.html', 'w', encoding='utf-8') as htmlfile:
        htmlfile.write(html_content)
    
    print(f"\nHTML file also created: 'Data_Structures_Programs.html'")
    print("Open the HTML file in a browser to see colored visualization!")

if __name__ == "__main__":
    main()
