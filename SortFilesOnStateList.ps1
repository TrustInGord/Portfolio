# Define the order of states
$states = @(
    "Alabama", "Arkansas", "Illinois", "Tennessee", "Wyoming", "New Jersey", 
    "Kansas", "Louisiana", "Nevada", "Montana", "New Mexico", "Oklahoma", 
    "Missouri", "Oregon", "Hawaii", "Massachusetts", "Ohio", "Virgin Islands", 
    "Mariana Islands", "Guam", "Puerto Rico", "New Hampshire", "Nebraska", 
    "Iowa", "Alaska", "Utah", "California", "North Carolina", "South Carolina", 
    "Maine", "New York", "Arizona", "Pennsylvania", "Michigan", "Minnesota", 
    "North Dakota", "South Dakota", "West Virginia", "Virginia", "Florida", 
    "Wisconsin", "Georgia", "Washington", "American Samoa", "Texas", "Kentucky", 
    "Mississippi", "Connecticut", "Colorado", "Maryland", "Idaho", "Rhode Island", 
    "Vermont", "Indiana", "Delaware"
)

# Directory containing the .webp files
$directory = "C:\Path\To\Your\Files"

# Change to the specified directory
Set-Location -Path $directory

# Loop through each state and rename the file
for ($i = 0; $i -lt $states.Count; $i++) {
    $state = $states[$i]
    $order = $i + 1

    # Define the original and new file names
    $originalFileName = "$state.webp"
    $newFileName = "{0:D2}-$state.webp" -f $order

    # Rename the file if it exists
    if (Test-Path -Path $originalFileName) {
        Rename-Item -Path $originalFileName -NewName $newFileName
    }
}
