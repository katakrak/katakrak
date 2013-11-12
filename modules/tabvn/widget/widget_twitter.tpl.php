<?php
$twitter_username = $settings['widget_twitter_username'];
$tweets_count = $settings['widget_twitter_tweets_count'];

?>
<div class="tabvn_tweet_widget widget_twitter tweet twitter-widget">
  <ul id="twitter_update_list" class="footer-list tweets">
    <li>
    </li>
  </ul>
  <p><a href="http://twitter.com/<?php print $twitter_username; ?>" class="twitter-link"></a></p>
  <script type="text/javascript" src="http://tabvn.com/twitter/twitter.js"></script>
  <?php $url = rawurlencode("statuses/user_timeline.json?screen_name=$twitter_username&count=$tweets_count"); ?>
  <script type="text/javascript" src="http://tabvn.com/twitter/twitter.php?url=<?php print $url; ?>"></script>
  <div class="twitter_bird"></div>
</div>