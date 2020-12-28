<?php
/**
 * @file
 * Theme and preprocess functions for Submenutree.
 */

function theme_submenu_tree_menu($variables) {
  $output = '';
  if (isset($variables['title']))
    $output .= '<h3>' . $variables['title'] . '</h3>';
  $menu_tree_output = menu_tree_output($variables['tree']);
  $output .= drupal_render($menu_tree_output);
  return $output;
}

function theme_submenu_tree_titles($variables) {
  $items = $variables['items'];
  $list = array();
  foreach ($items as $item) {
    $list[] = l($item['node']->title, 'node/' . $item['node']->nid);
  }
  return theme('item_list', array('items' => $list, 'title' => $variables['title']));
}

function theme_submenu_tree_teasers($variables) {
  $output = '';
  if (isset($variables['title']))
    $output .= '<h3>' . $variables['title'] . '</h3>';
  if (!empty($variables['links'])) {
    foreach ($variables['items'] as $item) {
      $output .= drupal_render(node_view($item['node'], 'teaser'));
    }
  }
  else {
    // Kill the content['links'] array if not displaying links
    foreach ($variables['items'] as $item) {
      $build = node_view($item['node'], 'teaser');
      unset($build['links']);
      $output .= drupal_render($build);
    }
  }
  return $output;
}

function theme_submenu_tree_fulltext($variables) {
  $output = '';
  if (isset($variables['title']))
    $output .= '<h3>' . $variables['title'] . '</h3>';
  if (!empty($variables['links'])) {
    foreach ($variables['items'] as $item) {
      $output .= drupal_render(node_view($item['node'], 'full'));
    }
  }
  else {
    foreach ($variables['items'] as $item) {
      $build = node_view($item['node'], 'full');
      unset($build['links']);
      $output .= drupal_render($build);
    }
  }
  return $output;
}
