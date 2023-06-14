# Set the directory path where your files are located
$directory = "C:\Path\to\your\directory"

# Get all files in the directory
$files = Get-ChildItem -Path $directory | Where-Object { $_.PSIsContainer -eq $false }

# Sort the files by creation date
$files = $files | Sort-Object CreationTime

# Initialize the counter
$counter = 0

# Loop through each file and rename it with a sequential number at the beginning
foreach ($file in $files) {
    $counter++
    $newName = "{0:D2}{1}" -f $counter, $file.Name
    $newPath = Join-Path -Path $directory -ChildPath $newName
    $file | Rename-Item -NewName $newPath
}
