Install-Package Magick.NET-Q8-AnyCPU

# Add the Magick.NET assembly
Add-Type -Path "C:\Path\To\Magick.NET-Q8-AnyCPU.dll"

# Directory containing the .webp files
$directory = "C:\Path\To\Your\Files"

# Change to the specified directory
Set-Location -Path $directory

# Loop through each .webp file and convert it to .png
Get-ChildItem -Filter *.webp | ForEach-Object {
    $webpFile = $_.FullName
    $pngFile = [System.IO.Path]::ChangeExtension($webpFile, ".png")

    # Load the .webp image
    $image = New-Object ImageMagick.MagickImage($webpFile)
    
    # Save the image as .png
    $image.Write($pngFile)
    
    # Dispose of the image object to free resources
    $image.Dispose()
}

Write-Output "Conversion complete."
