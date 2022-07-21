## This is a PowerShell script. This is part of a process of extracting zip file contents to specific folders 
## So that an Excel dashboard can use that information.
## We use an array of names, a loop, and archive location.

cd ".\Downloads"

#Zip Files's Names
$vzip = "The Price Is Right - Without the Fluff - WM 91.zip", 
"Beat Bobby Flay - Without the Fluff.zip", 
"Forged In Fire - Without The Fluff.zip", 
"Card Sharks - Without The Fluff.zip", 
"1 VS 100 - Without the Fluff.zip", 
"Wheel of Fortune - Without the Fluff.zip", 
"Chopped... Chopped - Without the Fluff.zip", 
"Kitchen - Without the Fluff - The Shortcut.zip", 
"The Wall - Without The Fluff - The Shortcut.zip", 
"Pawn Stars - Without the Fluff.zip", 
"Make A Deal - Without the Fluff - The Shortcut.zip", 
"Moment of Truth - Without the Fluff.zip", 
"Pooch Perfect - Without the Fluff - The Shortcut.zip", 
"Match Game - Without the Fluff.zip", 
"Blockbusters - Without the Fluff.zip", 
"Hollywood Squares - Without the Fluff.zip", 
"Storage Wars - Without the Fluff.zip", 
"Family Feud - Without the Fluff.zip", 
"Pointless - Without The Fluff + Fan Gift.zip", 
"Man Vs Food - Without the Fluff.zip", 
"Who Wants To Be A Millionaire - Without the Fluff.zip", 
"Orange County Choppers - Without The Fluff.zip", 
"Holey Moley - Without the Fluff + Art Gift.zip", 
"Fear Factor - Without The Fluff.zip",
"American Gladiators - Without the Fluff.zip", 
"MasterChef - Without The Fluff.zip", 
"Paternity Court - Without the Fluff.zip", 
"Deal Or No Deal In About 4 Minutes - Without the Fluff.zip", 
"RBT (Random Breathalyzer Testing) Australia - Without the Fluff.zip", 
"Exit List - Without the Fluff.zip", 
"Finding Bigfoot - Baby Bigfoot - Without The Fluff #Shorts #Horizontal.zip", 
"Cube in under 20 minutes).zip", 
"Drag Race Snatch Game Without the Fluff.zip", 
"The Maury Povich Show In Under 5 Minutes - Without The Fluff.zip", 
"Queen For A Day - A Terrible Game Show! - Without the Fluff.zip", 
"Kardashians (In About 4 minutes) - Without the Fluff.zip", 
"Distraction - Without the Fluff.zip", 
"Junior Part 1 - Without the Fluff.zip", 
"Awards Oscars (1998) (From 2 Hours to 16 minutes) - Without the Fluff.zip", 
"American Football - Without the Fluff.zip", 
"Roast Battle - Without The Fluff (Down from 22 minutes to 7).zip", 
"The Chase US - Without The Fluff (Now 42% the Size).zip", 
"Gong Show - Without The Fluff (Now 48% the Size).zip",
"Ninja Warrior - Without the Fluff - Now 38% the Size.zip",
"The Gord.zip"



#Zip File's Extraction Locations

$vdest = ".\Backend\PriceIsRight", 
".\Backend\BeatBobby", 
".\Backend\Forged", 
".\Backend\CardShark", 
".\Backend\1vs100", 
".\Backend\Wheel", 
".\Backend\Chopped", 
".\Backend\HellsKitch", 
".\Backend\Wall", 
".\Backend\PawnStar", 
".\Backend\LMAD", 
".\Backend\MomentOfT", 
".\Backend\Pooch", 
".\Backend\MatchGame", 
".\Backend\BlockBusters", 
".\Backend\HollywoodS", 
".\Backend\StorageW", 
".\Backend\FamilyFeud", 
".\Backend\Pointless", 
".\Backend\ManVsFood", 
".\Backend\WWTBAM", 
".\Backend\OCC", 
".\Backend\Holey", 
".\Backend\FearFac", 
".\Backend\Glads", 
".\Backend\Masterchef", 
".\Backend\Paternity", 
".\Backend\DealOrNo", 
".\Backend\RBT", 
".\Backend\ExitList", 
".\Backend\Bigfoot", 
".\Backend\Min2Win", 
".\Backend\Drag", 
".\Backend\Maury", 
".\Backend\Queen", 
".\Backend\Kard", 
".\Backend\Distraction", 
".\Backend\Chopjr",
".\Backend\Oscars",
".\Backend\Football", 
".\Backend\Roast", 
".\Backend\Chase", 
".\Backend\Gong", 
".\Backend\ANW", 
".\Backend\Audience"


#Zip Archive Location
$varch = "\Backend\SBat\Old"

#Loop through length of vzip
for($i = 0; $i -lt $vzip.length; $i++){

$vpath = get-childitem "*$($vzip[$i])" -name
$vpath

        #Expand audience zip to destinations
        Expand-Archive -LiteralPath $vpath -DestinationPath $vdest[$i] -force

        #Move-Item -Path $vpath -Destination $varch 
	Move-Item -Path $vpath -Destination ".\Backend\SBat\Old"

}
