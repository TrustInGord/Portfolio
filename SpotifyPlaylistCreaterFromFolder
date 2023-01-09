$dir = "C:\path\to\folder"
$outFile = "C:\path\to\songlist.txt"

# Get a list of all MP3 files in the directory
$mp3Files = Get-ChildItem $dir -Filter "*.mp3"

# Open the output file for writing
$out = [System.IO.StreamWriter] $outFile

# Write the names of the MP3 files to the file
foreach ($file in $mp3Files) {
    $out.WriteLine($file.Name)
}

# Close the output file
$out.Close()

# Replace YOUR_CLIENT_ID and YOUR_CLIENT_SECRET with your actual client ID and secret
$clientId = "YOUR_CLIENT_ID"
$clientSecret = "YOUR_CLIENT_SECRET"

# The ID of the playlist you want to add songs to
$playlistId = "YOUR_PLAYLIST_ID"

# The file containing the list of song names
$songListFile = "C:\path\to\songlist.txt"

# Read the list of song names from the file
$songList = Get-Content $songListFile

# Get an access token to authenticate the request
$authResponse = Invoke-RestMethod -Method Post -Uri "https://accounts.spotify.com/api/token" -ContentType "application/x-www-form-urlencoded" -Body "grant_type=client_credentials" -Headers @{"Authorization"="Basic $( [System.Convert]::ToBase64String([System.Text.Encoding]::ASCII.GetBytes($clientId + ':' + $clientSecret)))" }
$accessToken = $authResponse.access_token

# Add the songs to the playlist
foreach ($song in $songList) {
    $response = Invoke-RestMethod -Method Post -Uri "https://api.spotify.com/v1/playlists/$playlistId/tracks?uris=spotify:track:$song" -Headers @{"Authorization"="Bearer $accessToken"}
    if ($response.error -ne $null) {
        Write-Output "Error adding song: $song"
    }
}
