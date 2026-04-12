#!/bin/bash

# Default commit message if none is provided
MSG="Auto-update: $(date +'%Y-%m-%d %H:%M:%S')"

# If an argument is provided, use it as the commit message
if [ ! -z "$1" ]; then
    MSG="$1"
fi

echo "📦 Adding changes..."
git add .

echo "📝 Committing: '$MSG'"
git commit -m "$MSG"

echo "🚀 Pushing to remote..."
git push

echo "✅ Done!"